#include "cef/libcef/common/resource_bundle_delegate.h"

#include "cef/libcef/common/app_manager.h"
#include "cef/libcef/features/runtime.h"

CefResourceBundleDelegate::CefResourceBundleDelegate() {
#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
  // Alloy bootstrap explicitly enables pack file loading in
  // AlloyMainDelegate::InitializeResourceBundle, and it is otherwise disabled
  // by default. Chrome bootstrap does not support this.
  allow_pack_file_load_ = cef::IsChromeRuntimeEnabled();
#endif
}

base::FilePath CefResourceBundleDelegate::GetPathForResourcePack(
    const base::FilePath& pack_path,
    ui::ResourceScaleFactor scale_factor) {
#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
  // Only allow the cef pack file to load.
  if (!pack_loading_disabled_ && allow_pack_file_load_) {
    return pack_path;
  }
  return base::FilePath();
#else
  return pack_path;
#endif
}

base::FilePath CefResourceBundleDelegate::GetPathForLocalePack(
    const base::FilePath& pack_path,
    const std::string& locale) {
#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
  if (!pack_loading_disabled_) {
    return pack_path;
  }
  return base::FilePath();
#else
  return pack_path;
#endif
}

gfx::Image CefResourceBundleDelegate::GetImageNamed(int resource_id) {
  return gfx::Image();
}

gfx::Image CefResourceBundleDelegate::GetNativeImageNamed(int resource_id) {
  return gfx::Image();
}

base::RefCountedMemory* CefResourceBundleDelegate::LoadDataResourceBytes(
    int resource_id,
    ui::ResourceScaleFactor scale_factor) {
  return nullptr;
}

std::optional<std::string> CefResourceBundleDelegate::LoadDataResourceString(
    int resource_id) {
  return std::nullopt;
}

bool CefResourceBundleDelegate::GetRawDataResource(
    int resource_id,
    ui::ResourceScaleFactor scale_factor,
    std::string_view* value) const {
  auto application = CefAppManager::Get()->GetApplication();
  if (application) {
    CefRefPtr<CefResourceBundleHandler> handler =
        application->GetResourceBundleHandler();
    if (handler.get()) {
      void* data = nullptr;
      size_t data_size = 0;
      if (scale_factor != ui::kScaleFactorNone) {
        if (handler->GetDataResourceForScale(
                resource_id, static_cast<cef_scale_factor_t>(scale_factor),
                data, data_size)) {
          *value = std::string_view(static_cast<char*>(data), data_size);
        }
      } else if (handler->GetDataResource(resource_id, data, data_size)) {
        *value = std::string_view(static_cast<char*>(data), data_size);
      }
    }
  }

#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
  if (pack_loading_disabled_) {
    return true;
  }
#endif

  return !value->empty();
}

bool CefResourceBundleDelegate::GetLocalizedString(
    int message_id,
    std::u16string* value) const {
  auto application = CefAppManager::Get()->GetApplication();
  if (application) {
    CefRefPtr<CefResourceBundleHandler> handler =
        application->GetResourceBundleHandler();
    if (handler.get()) {
      CefString cef_str;
      if (handler->GetLocalizedString(message_id, cef_str)) {
        *value = cef_str;
      }
    }
  }

#if BUILDFLAG(ENABLE_ALLOY_BOOTSTRAP)
  if (pack_loading_disabled_) {
    return true;
  }
#endif

  return !value->empty();
}
