# Adjust Extension for Defold

This extension wraps Adjust SDK for iOS (4.17.1) and Android (4.17.0). On other platforms this extension provides stub functions.

Use provided `AndroidManifest.xml` or copy Adjust entries into your existing one.

Follow official guides for more information:
- iOS https://github.com/adjust/ios_sdk/blob/master/README.md
- Android https://github.com/adjust/android_sdk/blob/master/README.md

# API reference

## adjust.init(params)

Call this function before invoking any other functions.

### `params` reference

- `app_token`, string, required. App token.
- `is_sandbox`, boolean, optional. Set to `true` to enable sandbox environment. Default is `false`.
- `app_secret`, table, optional. Number fields `id`, `info1`, `info2`, `info3`, `info4`.
- `default_tracker`, string, optional.
- `delay_start`, number, optional. Wait for this amount of seconds before sending data. Or until `adust.send_first_packages()` is called. Default is no delay.
- `is_device_known`, boolean, optional.
- `event_buffering`, boolean, optional. Set to `true` to enable batch transmition of packages. If your app sends a lot of events, it makes sense to batch them to lower network load. Default is `false`.
- `log_level`, string, optional. Log output level: `'assert'`, `'debug'`, `'error'`, `'supress'`, `'verbose'`, `'warn'`, `'info'`. Default is `'info'`.
- `process_name`, string, optional. Android only.
- `sdk_prefix`, string, optional.
- `send_in_background`, boolean, optional. If `true` the data is sent even in background.
- `user_agent`, string, optional.
- `listener`, function, optional. Receives events from the SDK. See events section below.

### Events reference

`listener` receives `event` table for each event phase.

#### Init event

Received when the extension is ready.

- `name`, string, `'adjust'`.
- `phase`, string, `'init'`.
- `is_error`, boolean, `false`.

#### Attribution changed event

Received when the attribution has been changed.

- `name`, string, `'adjust'`.
- `phase`, string, `'attribution_changed'`.
- `is_error`, boolean, `false`.
- `adgroup`, string.
- `adid`, string.
- `campaign`, string.
- `click_label`, string.
- `creative`, string.
- `network`, string.
- `tracker_name`, string.
- `tracker_token`, string.

#### Deeplink event

Received when a deeplink has been opened.

- `name`, string, `'adjust'`.
- `phase`, string, `'deeplink'`.
- `is_error`, boolean, `false`.
- `url`, string. Deeplink URL.

### Event tracking event

Received when the SDK successfully sent an event with `adjust.track_event()` over the network or failed to do so.

- `name`, string, `'adjust'`.
- `phase`, string, `'event_tracking'`.
- `is_error`, boolean, `false` in case of a success, `true` in case of an error.
- `callback_id`, string.
- `adid`, string.
- `message`, string.
- `timestamp`, string.
- `will_retry`, boolean. In case of an error shows if the SDK attempts to retry.

### Session tracking event

Received when the SDK successfully sent session info over the network or failed to do so.

- `name`, string, `'adjust'`.
- `phase`, string, `'session_tracking'`.
- `is_error`, boolean, `false` in case of a success, `true` in case of an error.
- `adid`, string.
- `message`, string.
- `timestamp`, string.
- `will_retry`, boolean. In case of an error shows if the SDK attempts to retry.

### Syntax

```language-lua
adjust.init{
	app_token= '9gb9tifsuhvk',
	is_sandbox = false,
	app_secret = {id = 0, info1 = 0, info2 = 0, info3 = 0, info4 = 0},
	default_tracker = '',
	delay_start = 0,
	is_device_known = false,
	event_buffering = false,
	log_level = 'info',
	process_name = '',
	sdk_prefix = '',
	send_in_background = false,
	user_agent = '',
	listener = function(event)
		print(event.phase, event.is_error)
	end
}
```
___
## adjust.track_event(params)

Track an event via the SDK.

### `params` reference

- `token`, string, required. Event token.
- `callback_id`, string, optional.
- `revenue`, number, optional. Provide purchase information. Both `revenue` and `currency` must be set for that.
- `currency`, string, optional. Purchase currency code, e.g. `'USD'` or `'EUR'`.
- `transaction_id`, string, optional. Providing transaction id prevents event duplication.
- `partner_parameters`, table, optional. A key-value set of extra partner parameters. Keys and values must be strings.
- `callback_parameters`, table, optional. A key-value set of extra callback parameters. Keys and values must be strings.

### Syntax

```language-lua
adjust.track_event{
	token = 'tsgtia',
	callback_id = 'some_id',
	revenue = 0.99,
	currency = 'USD',
	transaction_id = '',
	partner_parameters = {
		partner_key1 = 'partner_value1',
		partner_key2 = 'partner_value2'
	},
	callback_parameters = {
		callback_key1 = 'callback_value1',
		callback_key2 = 'callback_value2'
	}
}
```

___
## adjust.set_session_parameters(params)

Set global session and callback parameters to be sent with each `adjust.track_event()` call. Calling this function again resets all parameters to new values. If `partner_parameters` or `callback_parameters` is omitted, it's not reset.

### Syntax

```language-lua
-- Set all parameters.
adjust.set_session_parameters{
	partner_parameters = {
		partner_key1 = 'partner_value1',
		partner_key2 = 'partner_value2'
	},
	callback_parameters = {
		callback_key1 = 'callback_value1',
		callback_key2 = 'callback_value2'
	}
}

-- Reset callback_parameters only.
adjust.set_session_parameters{
	callback_parameters = {
		callback_key1 = 'new_callback_value1'
	}
}
```

___
## adjust.set_enabled(is_enabled)

If `is_enabled` is `false`, the SDK is disabled and all interaction is paused. If `is_enabled` is `true` the SDK is resumed.

### Syntax

```language-lua
adjust.set_enabled(false)
```

___
## adjust.set_pushtoken(token)

### Syntax

```language-lua
adjust.set_pushtoken('')
```

___
## adjust.set_offline_mode(is_offline)

If `is_offline` is `true`, the SDK enters offline mode and delays network activity until the offline mode is turned off.

### Syntax

```language-lua
adjust.set_offline_mode(true)
```

___
## adjust.send_first_packages()

Call this if `delay_start` is used and you want to start the SDK before the delay is elapsed.

### Syntax

```language-lua
adjust.send_first_packages()
```

___
## adjust.app_will_open_url(url)

Track URL opening.

### Syntax

```language-lua
adjust.app_will_open_url('http://')
```

___
## adjust.gdpr_forget_me()

### Syntax

```language-lua
adjust.gdpr_forget_me()
```

___
## adjust.get_attribution()

Returns a table, attribution information:

- `adgroup`, string.
- `adid`, string.
- `campaign`, string.
- `click_label`, string.
- `creative`, string.
- `network`, string.
- `tracker_name`, string.
- `tracker_token`, string.

### Syntax

```language-lua
local attribution = adjust.get_attribution()
if attribution then
	print(attribution.adid)
end
```

___
## adjust.get_adid()

Returns string, `adid`.

### Syntax

```language-lua
local adid = adjust.get_adid()
print(adid)
```

___
## adjust.get_amazon_ad_id()

Returns string, Amazon advertising identifier. Android only.

### Syntax

```language-lua
local amazon_ad_id = adjust.get_amazon_ad_id()
print(amazon_ad_id)
```

___
## adjust.get_google_ad_id(listener)

Request Google advertising identifier. `listener` receives an `event` table:

- `name`, string, `'google_ad_id'`.
- `is_error`, boolean, `false`.
- `google_ad_id`, string, advertising identifier.

### Syntax

```language-lua
adjust.get_google_ad_id(function(event)
	print(event.google_ad_id)
end)
```

___
## adjust.get_sdk_version()

Returns string, Adjust SDK version.

### Syntax

```language-lua
local sdk_version = adjust.get_sdk_version()
print(sdk_version)
```

___
## adjust.get_idfa()

Returns string, IDFA. iOS only.

### Syntax

```language-lua
local idfa = adjust.get_idfa()
print(idfa)
```