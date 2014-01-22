<?php

/**
 * Implements hook_preprocess_page().
 */
function taskmanagertheme_preprocess_page(&$variables) {
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
   drupal_add_library('system', 'jquery.cookie');

  global $user;
  drupal_add_js(array('user_js_uid' => $user->uid), 'setting');
}
