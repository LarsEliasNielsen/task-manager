<?php

/**
 * Implements hook_preprocess_views_view_table().
 */
function taskmanagertheme_preprocess_views_view_table(&$vars) {
  if ($vars['view']->name == "columns") {
    // emptying header array for table format
    $vars['header'] = array();
  }
}