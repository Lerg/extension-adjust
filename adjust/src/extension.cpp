#include "extension.h"

// This is the entry point of the extension. It defines Lua API of the extension.

static const luaL_reg lua_functions[] = {
	{"init", EXTENSION_INIT},
	{"track_event", EXTENSION_TRACK_EVENT},
	{"set_session_parameters", EXTENSION_SET_SESSION_PARAMETERS},
	{"set_enabled", EXTENSION_SET_ENABLED},
	{"set_pushtoken", EXTENSION_SET_PUSHTOKEN},
	{"set_offline_mode", EXTENSION_SET_OFFLINE_MODE},
	{"send_first_packages", EXTENSION_SEND_FIRST_PACKAGES},
	{"app_will_open_url", EXTENSION_APP_WILL_OPEN_URL},
	{"gdpr_forget_me", EXTENSION_GDPR_FORGET_ME},
	{"get_attribution", EXTENSION_GET_ATTRIBUTION},
	{"get_adid", EXTENSION_GET_ADID},
	{"get_amazon_ad_id", EXTENSION_GET_AMAZON_AD_ID},
	{"get_google_ad_id", EXTENSION_GET_GOOGLE_AD_ID},
	{"get_sdk_version", EXTENSION_GET_SDK_VERSION},
	{"get_idfa", EXTENSION_GET_IDFA},
	{0, 0}
};

dmExtension::Result APP_INITIALIZE(dmExtension::AppParams *params) {
	return dmExtension::RESULT_OK;
}

dmExtension::Result APP_FINALIZE(dmExtension::AppParams *params) {
	return dmExtension::RESULT_OK;
}

dmExtension::Result INITIALIZE(dmExtension::Params *params) {
	luaL_register(params->m_L, EXTENSION_NAME_STRING, lua_functions);
	lua_pop(params->m_L, 1);
	EXTENSION_INITIALIZE(params->m_L);
	return dmExtension::RESULT_OK;
}

dmExtension::Result UPDATE(dmExtension::Params *params) {
	EXTENSION_UPDATE(params->m_L);
	return dmExtension::RESULT_OK;
}

void EXTENSION_ON_EVENT(dmExtension::Params *params, const dmExtension::Event *event) {
	switch (event->m_Event) {
		case dmExtension::EVENT_ID_ACTIVATEAPP:
			EXTENSION_APP_ACTIVATE(params->m_L);
			break;
		case dmExtension::EVENT_ID_DEACTIVATEAPP:
			EXTENSION_APP_DEACTIVATE(params->m_L);
			break;
	}
}

dmExtension::Result FINALIZE(dmExtension::Params *params) {
	EXTENSION_FINALIZE(params->m_L);
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, EXTENSION_NAME_STRING, APP_INITIALIZE, APP_FINALIZE, INITIALIZE, UPDATE, EXTENSION_ON_EVENT, FINALIZE)