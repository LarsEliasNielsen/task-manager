<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * TaskEditTheme theme.
 */

function taskedittheme_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'task_node_form' && !isset($form['nid']['#value'])) {
    // redirect after we created a new node
    $form['actions']['submit']['#submit'][] = 'node_reference_redirect';
  } elseif ($form_id == 'task_node_form' && isset($form['nid']['#value'])) {
    // redirect after we updated a node
    $form['#submit'][] = 'node_save_reference_redirect';
  }
}

function node_reference_redirect($form, &$form_state) {
  global $base_url;
  $form_state['redirect'] = $base_url;
}

function node_save_reference_redirect($form, &$form_state) {
  global $base_url;
  $form_state['redirect'] = $base_url;
}