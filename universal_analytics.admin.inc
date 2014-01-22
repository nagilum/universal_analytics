<?php

/**
 * @file
 * Admin interface for the module configuration.
 */

/**
 * Interface for the main configuration.
 */
function universal_analytics_config() {
  $form = array(
    'ua_client_id' => array(
      '#type'          => 'textfield',
      '#title'         => t('Client ID'),
      '#description'   => t('The client ID in Google Analytics.'),
      '#default_value' => variable_get('ua_client_id', ''),
    ),
    'ua_tracking_id' => array(
      '#type'          => 'textfield',
      '#title'         => t('Tracking ID'),
      '#description'   => t('The tracking ID in Google Analytics. i.e. UA-XXXXX-X.'),
      '#default_value' => variable_get('ua_tracking_id', ''),
    ),
    'ua_event' => array(
      '#type'          => 'textfield',
      '#title'         => t('Event'),
      '#description'   => t('If you only track one even with this module, you can enter the event here and only track action with the ua_track() function.'),
      '#default_value' => variable_get('ua_event', ''),
    ),
    'options' => array(
      '#type'        => 'fieldset',
      '#title'       => t('Options'),
      '#description' => t('Options for extra tracking data.'),
      '#collapsible' => TRUE,
      '#collapsed'   => TRUE,

      'ua_autotrack_server_name' => array(
        '#type'          => 'checkbox',
        '#title'         => t('Track server name'),
        '#description'   => t('Automatically track server name from the server variables.'),
        '#default_value' => variable_get('ua_autotrack_server_name', TRUE),
      ),
      'ua_autotrack_request_uri' => array(
        '#type'          => 'checkbox',
        '#title'         => t('Track request URi'),
        '#description'   => t('Automatically track request URi from the server variables.'),
        '#default_value' => variable_get('ua_autotrack_server_name', TRUE),
      ),
      'ua_autotrack_http_referer' => array(
        '#type'          => 'checkbox',
        '#title'         => t('Track referer'),
        '#description'   => t('Automatically track referer from the server variables.'),
        '#default_value' => variable_get('ua_autotrack_server_name', TRUE),
      ),
      'ua_autotrack_http_user_agent' => array(
        '#type'          => 'checkbox',
        '#title'         => t('Track user agent'),
        '#description'   => t('Automatically track user agent from the server variables.'),
        '#default_value' => variable_get('ua_autotrack_server_name', TRUE),
      ),
    ),
    'automation' => array(
      '#type'        => 'fieldset',
      '#title'       => t('Automation'),
      '#description' => t('Options for automatic tracking.'),
      '#collapsible' => TRUE,
      '#collapsed'   => TRUE,

      'ua_auto_track' => array(
        '#type'          => 'checkbox',
        '#title'         => t('Track each visit'),
        '#description'   => t('Automatically track each time the hook_init() function is loaded.'),
        '#default_value' => variable_get('ua_auto_track', FALSE),
      ),
    ),
  );

  return system_settings_form($form);
}
