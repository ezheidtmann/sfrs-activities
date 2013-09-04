<?php
/**
 * @file
 * s4rs_activity_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function s4rs_activity_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: administer comments on own s4rs_activity.
  $permissions['administer comments on own s4rs_activity'] = array(
    'name' => 'administer comments on own s4rs_activity',
    'roles' => array(
      0 => 'administrator',
      1 => 'teacher',
    ),
    'module' => 'commentaccess',
  );

  // Exported permission: administer sticky comments.
  $permissions['administer sticky comments'] = array(
    'name' => 'administer sticky comments',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
    ),
    'module' => 'stickythreads',
  );

  // Exported permission: approve comments on own s4rs_activity.
  $permissions['approve comments on own s4rs_activity'] = array(
    'name' => 'approve comments on own s4rs_activity',
    'roles' => array(
      0 => 'administrator',
      1 => 'teacher',
    ),
    'module' => 'commentaccess',
  );

  // Exported permission: create s4rs_activity content.
  $permissions['create s4rs_activity content'] = array(
    'name' => 'create s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any s4rs_activity content.
  $permissions['delete any s4rs_activity content'] = array(
    'name' => 'delete any s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete comments on own s4rs_activity.
  $permissions['delete comments on own s4rs_activity'] = array(
    'name' => 'delete comments on own s4rs_activity',
    'roles' => array(
      0 => 'administrator',
      1 => 'teacher',
    ),
    'module' => 'commentaccess',
  );

  // Exported permission: delete own s4rs_activity content.
  $permissions['delete own s4rs_activity content'] = array(
    'name' => 'delete own s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any s4rs_activity content.
  $permissions['edit any s4rs_activity content'] = array(
    'name' => 'edit any s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: edit own s4rs_activity content.
  $permissions['edit own s4rs_activity content'] = array(
    'name' => 'edit own s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: edit revisions.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
      2 => 'teacher',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: publish revisions.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of any s4rs_activity content.
  $permissions['publish revisions of any s4rs_activity content'] = array(
    'name' => 'publish revisions of any s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of own s4rs_activity content.
  $permissions['publish revisions of own s4rs_activity content'] = array(
    'name' => 'publish revisions of own s4rs_activity content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
      2 => 'teacher',
    ),
    'module' => 'comment',
  );

  // Exported permission: unpublish current revision.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revision status messages.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'administrator',
      2 => 'teacher',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of any s4rs_activity content.
  $permissions['view revisions of any s4rs_activity content'] = array(
    'name' => 'view revisions of any s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of own s4rs_activity content.
  $permissions['view revisions of own s4rs_activity content'] = array(
    'name' => 'view revisions of own s4rs_activity content',
    'roles' => array(
      0 => 'activity moderator',
      1 => 'teacher',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
