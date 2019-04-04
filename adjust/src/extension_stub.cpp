#if !defined(DM_PLATFORM_IOS) && !defined(DM_PLATFORM_ANDROID)

#include <dmsdk/sdk.h>
#include "extension.h"

int EXTENSION_INIT(lua_State *L) {
	dmLogInfo("init");
	return 0;
}

int EXTENSION_TRACK_EVENT(lua_State *L) {
	dmLogInfo("track_event");
	return 0;
}

int EXTENSION_SET_SESSION_PARAMETERS(lua_State *L) {
	dmLogInfo("set_session_parameters");
	return 0;
}

int EXTENSION_SET_ENABLED(lua_State *L) {
	dmLogInfo("set_enabled");
	return 0;
}

int EXTENSION_SET_PUSHTOKEN(lua_State *L) {
	dmLogInfo("set_pushtoken");
	return 0;
}

int EXTENSION_SET_OFFLINE_MODE(lua_State *L) {
	dmLogInfo("set_offline_mode");
	return 0;
}

int EXTENSION_SEND_FIRST_PACKAGES(lua_State *L) {
	dmLogInfo("send_first_packages");
	return 0;
}

int EXTENSION_APP_WILL_OPEN_URL(lua_State *L) {
	dmLogInfo("app_will_open_url");
	return 0;
}

int EXTENSION_GDPR_FORGET_ME(lua_State *L) {
	dmLogInfo("gdpr_forget_me");
	return 0;
}

int EXTENSION_GET_ATTRIBUTION(lua_State *L) {
	dmLogInfo("get_attribution");
	return 0;
}

int EXTENSION_GET_ADID(lua_State *L) {
	dmLogInfo("get_adid");
	return 0;
}

int EXTENSION_GET_AMAZON_AD_ID(lua_State *L) {
	dmLogInfo("get_amazon_ad_id");
	return 0;
}

int EXTENSION_GET_GOOGLE_AD_ID(lua_State *L) {
	dmLogInfo("get_google_ad_id");
	return 0;
}

int EXTENSION_GET_SDK_VERSION(lua_State *L) {
	dmLogInfo("get_sdk_version");
	return 0;
}

int EXTENSION_GET_IDFA(lua_State *L) {
	dmLogInfo("get_idfa");
	return 0;
}

void EXTENSION_INITIALIZE(lua_State *L) {
}

void EXTENSION_UPDATE(lua_State *L) {
}

void EXTENSION_APP_ACTIVATE(lua_State *L) {
}

void EXTENSION_APP_DEACTIVATE(lua_State *L) {
}

void EXTENSION_FINALIZE(lua_State *L) {
}

#endif
