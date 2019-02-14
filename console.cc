#include "napi.h"
#include <Windows.h>

using namespace Napi;

void hide(CallbackInfo const& info)
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void show(CallbackInfo const& info)
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

Value isVisible(CallbackInfo const& info)
{
    auto result = ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
    return Boolean::New(info.Env(), result);
}

#define EXPORT_FUNCTION(name) \
    PropertyDescriptor::Function(env, exports, #name, name, napi_enumerable)

Object module_init(Env env, Object exports) {
    exports.DefineProperties({
        EXPORT_FUNCTION(show),
        EXPORT_FUNCTION(hide),
        EXPORT_FUNCTION(isVisible),
    });
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, module_init);