#!/usr/bin/env python
# Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license
# that can be found in the LICENSE file.
"""
A simple utility function to merge pack resource files into a single resource file.
"""

from __future__ import absolute_import
from __future__ import print_function
from cef_parser import get_copyright
from file_util import *
import os
import re
import string
import sys


def MakeFileSegment(input, all_names):
  result = """

// ---------------------------------------------------------------------------
// From $FILE$:
"""

  filename = os.path.split(input)[1]
  result = result.replace('$FILE$', filename)

  contents = read_file(input)

  # Format for Windows builds with resource whitelisting enabled [1]:
  #   #define IDR_RESOURCE_NAME (::ui::WhitelistedResource<12345>(), 12345)
  # Format for other builds:
  #   #define IDR_RESOURCE_NAME 12345
  # [1] See https://crbug.com/684788#c18

  regex = r'#define\s([A-Za-z0-9_]{1,})\s+'
  if contents.find('ui::WhitelistedResource') > 0:
    regex += r'.*<'
  regex += r'([0-9]{1,})'

  # identify the defines in the file
  p = re.compile(regex)
  list = p.findall(contents)
  for name, id in list:
    # If the same define exists in multiple files add a suffix.
    if name in all_names:
      all_names[name] += 1
      name += '_%d' % all_names[name]
    else:
      all_names[name] = 1

    result += "\n#define %s %s" % (name, id)

  return result


def MakeFile(output, input):
  # header string
  result = get_copyright(full=True, translator=False) + \
"""//
// ---------------------------------------------------------------------------
//
// This file is generated by the make_pack_header.py tool.
//

#ifndef $GUARD$
#define $GUARD$
#pragma once"""

  # sort the input files by name
  input = sorted(input, key=lambda path: os.path.split(path)[1])

  all_names = {}

  # generate the file segments
  for file in input:
    result += MakeFileSegment(file, all_names)

  # footer string
  result += \
"""

#endif  // $GUARD$
"""

  # add the guard string
  filename = os.path.split(output)[1]
  guard = 'CEF_INCLUDE_' + filename.replace('.', '_').upper() + '_'
  result = result.replace('$GUARD$', guard)

  write_file_if_changed(output, result)


def main(argv):
  if len(argv) < 3:
    print(("Usage:\n  %s <output_filename> <input_file1> [input_file2] ... " %
           argv[0]))
    sys.exit(-1)
  MakeFile(argv[1], argv[2:])


if '__main__' == __name__:
  main(sys.argv)