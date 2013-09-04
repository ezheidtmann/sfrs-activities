<?php
/**
 * @file
 * s4rs_activity_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function s4rs_activity_permissions_user_default_roles() {
  $roles = array();

  // Exported role: activity moderator.
  $roles['activity moderator'] = array(
    'name' => 'activity moderator',
    'weight' => '4',
    'machine_name' => 'activity_moderator',
  );

  // Exported role: teacher.
  $roles['teacher'] = array(
    'name' => 'teacher',
    'weight' => '3',
    'machine_name' => 'teacher',
  );

  return $roles;
}
