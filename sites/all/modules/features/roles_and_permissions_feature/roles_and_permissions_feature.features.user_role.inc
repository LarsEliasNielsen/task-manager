<?php
/**
 * @file
 * roles_and_permissions_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function roles_and_permissions_feature_user_default_roles() {
  $roles = array();

  // Exported role: Developer.
  $roles['Developer'] = array(
    'name' => 'Developer',
    'weight' => 3,
  );

  // Exported role: Project Manager.
  $roles['Project Manager'] = array(
    'name' => 'Project Manager',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
