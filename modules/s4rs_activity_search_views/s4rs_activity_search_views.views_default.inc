<?php
/**
 * @file
 * s4rs_activity_search_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function s4rs_activity_search_views_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'activity_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_activity_index';
  $view->human_name = 'activity search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'title',
    'field_subject_areas' => 'title',
    'field_grade_level' => 'title',
    'field_activity_pdf' => 'field_activity_pdf',
    'nothing' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject_areas' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grade_level' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_pdf' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Subject Area(s) */
  $handler->display->display_options['fields']['field_subject_areas']['id'] = 'field_subject_areas';
  $handler->display->display_options['fields']['field_subject_areas']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['fields']['field_subject_areas']['field'] = 'field_subject_areas';
  $handler->display->display_options['fields']['field_subject_areas']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_subject_areas']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_subject_areas']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_subject_areas']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_subject_areas']['view_mode'] = 'full';
  /* Field: Indexed Node: Grade Level(s) */
  $handler->display->display_options['fields']['field_grade_level']['id'] = 'field_grade_level';
  $handler->display->display_options['fields']['field_grade_level']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['fields']['field_grade_level']['field'] = 'field_grade_level';
  $handler->display->display_options['fields']['field_grade_level']['label'] = 'Grades';
  $handler->display->display_options['fields']['field_grade_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_grade_level']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_grade_level']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_grade_level']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_grade_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_grade_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_grade_level']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_grade_level']['view_mode'] = 'full';
  /* Field: Subject/Grades blurb */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Subject/Grades blurb';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<em>[field_subject_areas]</em> in grade(s) <em>[field_grade_level]</em>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '120',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Indexed Node: Activity PDF */
  $handler->display->display_options['fields']['field_activity_pdf']['id'] = 'field_activity_pdf';
  $handler->display->display_options['fields']['field_activity_pdf']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['fields']['field_activity_pdf']['field'] = 'field_activity_pdf';
  $handler->display->display_options['fields']['field_activity_pdf']['label'] = 'Files';
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_activity_pdf']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_activity_pdf']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_activity_pdf']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_activity_pdf']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_activity_pdf']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_activity_pdf']['separator'] = '<br />';
  $handler->display->display_options['fields']['field_activity_pdf']['field_api_classes'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Sort criterion: Indexed Node: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_activity_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_materials' => 'field_materials',
    'search_api_viewed' => 'search_api_viewed',
    'attachments_field_activity_pdf' => 'attachments_field_activity_pdf',
    'body:value' => 'body:value',
    'field_activity_pdf:description' => 'field_activity_pdf:description',
    'field_student_key_vocab:name' => 'field_student_key_vocab:name',
    'field_activity_pdf:file:name' => 'field_activity_pdf:file:name',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'activity-search';
  $export['activity_search'] = $view;

  return $export;
}
