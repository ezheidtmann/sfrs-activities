<?php
/**
 * @file
 * s4rs_activity_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function s4rs_activity_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'current_activity_search';
  $item->label = 'Current activity search';
  $item->settings = array(
    'items' => array(
      'results' => array(
        'id' => 'text',
        'label' => 'Results',
        'text' => 'Search found [facetapi_results:result-count] result.',
        'plural' => 1,
        'text_plural' => 'Search found [facetapi_results:result-count] results.',
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 0,
        'element' => '0',
        'css' => 0,
        'classes' => '',
        'weight' => '-50',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'active items',
        'pattern' => '[facetapi_active:active-value]',
        'keys' => 1,
        'css' => 0,
        'classes' => '',
        'nofollow' => 1,
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => 0,
    ),
  );
  $export['current_activity_search'] = $item;

  return $export;
}
