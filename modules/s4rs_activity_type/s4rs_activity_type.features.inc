<?php
/**
 * @file
 * s4rs_activity_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function s4rs_activity_type_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function s4rs_activity_type_flag_default_flags() {
  $flags = array();
  // Exported flag: "Sticky".
  $flags['comment_sticky'] = array(
    'content_type' => 'comment',
    'title' => 'Sticky',
    'global' => '1',
    'types' => array(
      0 => 'comment_node_s4rs_activity',
    ),
    'flag_short' => 'make sticky',
    'flag_long' => 'Mark this comment as sticky',
    'flag_message' => 'This comment is now sticky.',
    'unflag_short' => 'remove sticky',
    'unflag_long' => 'Remove sticky status from this comment',
    'unflag_message' => 'This comment has been un-stuck',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => 'node_own',
    'show_on_comment' => 1,
    'module' => 's4rs_activity_type',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function s4rs_activity_type_node_info() {
  $items = array(
    's4rs_activity' => array(
      'name' => t('S4RS Activity'),
      'base' => 'node_content',
      'description' => t('Create new activity page.'),
      'has_title' => '1',
      'title_label' => t('Activity Name'),
      'help' => t('[TODO: write this submission guideline]

You are free to edit this activity, but please note that all changes must be approved by Solar4RSchools staff before they are made public. '),
    ),
  );
  return $items;
}
