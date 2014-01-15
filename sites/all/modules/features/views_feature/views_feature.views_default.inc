<?php
/**
 * @file
 * views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'columns';
  $view->description = 'Backlog, Current and Done columns';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Columns';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Backlog';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'state';

  /* Display: Backlog */
  $handler = $view->new_display('block', 'Backlog', 'backlog');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'You have not created any tasks.';
  $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/edit';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';

  /* Display: Current */
  $handler = $view->new_display('block', 'Current', 'current');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'You have no current tasks.';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'state';

  /* Display: Done */
  $handler = $view->new_display('block', 'Done', 'done');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Done';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'You have no finished tasks.';
  $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'state';
  $export['columns'] = $view;

  $view = new view();
  $view->name = 'revision_history';
  $view->description = 'History of Tasks';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content (historical data): State */
  $handler->display->display_options['fields']['field_state-revision_id']['id'] = 'field_state-revision_id';
  $handler->display->display_options['fields']['field_state-revision_id']['table'] = 'field_revision_field_state';
  $handler->display->display_options['fields']['field_state-revision_id']['field'] = 'field_state-revision_id';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content (historical data): State (field_state) */
  $handler->display->display_options['filters']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['table'] = 'field_revision_field_state';
  $handler->display->display_options['filters']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator_id'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['label'] = 'State (field_state)';
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['identifier'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_state_tid']['vocabulary'] = 'state';

  /* Display: History */
  $handler = $view->new_display('block', 'History', 'history');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content (historical data): State */
  $handler->display->display_options['fields']['field_state-revision_id']['id'] = 'field_state-revision_id';
  $handler->display->display_options['fields']['field_state-revision_id']['table'] = 'field_revision_field_state';
  $handler->display->display_options['fields']['field_state-revision_id']['field'] = 'field_state-revision_id';
  $handler->display->display_options['fields']['field_state-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_state-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Field: Content revision: Revert link */
  $handler->display->display_options['fields']['revert_revision']['id'] = 'revert_revision';
  $handler->display->display_options['fields']['revert_revision']['table'] = 'node_revision';
  $handler->display->display_options['fields']['revert_revision']['field'] = 'revert_revision';
  $handler->display->display_options['fields']['revert_revision']['label'] = '';
  $handler->display->display_options['fields']['revert_revision']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Started */
  $handler = $view->new_display('attachment', 'Started', 'started_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Started';
  $handler->display->display_options['display_description'] = 'All revisions of \'Started\'';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;

  /* Display: Not started */
  $handler = $view->new_display('attachment', 'Not started', 'not_started_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Not started';
  $handler->display->display_options['display_description'] = 'All revisions of \'Not started\'';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content (historical data): State (field_state) */
  $handler->display->display_options['filters']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['table'] = 'field_revision_field_state';
  $handler->display->display_options['filters']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator_id'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['label'] = 'State (field_state)';
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['identifier'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_state_tid']['vocabulary'] = 'state';

  /* Display: Done */
  $handler = $view->new_display('attachment', 'Done', 'done_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Done';
  $handler->display->display_options['display_description'] = 'All revisions of \'Done\'';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content (historical data): State (field_state) */
  $handler->display->display_options['filters']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['table'] = 'field_revision_field_state';
  $handler->display->display_options['filters']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_state_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator_id'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['label'] = 'State (field_state)';
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['identifier'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_state_tid']['vocabulary'] = 'state';

  /* Display: Needs review */
  $handler = $view->new_display('attachment', 'Needs review', 'needs_review_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Needs review';
  $handler->display->display_options['display_description'] = 'All revisions of \'Needs review\'';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content (historical data): State (field_state) */
  $handler->display->display_options['filters']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['table'] = 'field_revision_field_state';
  $handler->display->display_options['filters']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator_id'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['label'] = 'State (field_state)';
  $handler->display->display_options['filters']['field_state_tid']['expose']['operator'] = 'field_state_tid_op';
  $handler->display->display_options['filters']['field_state_tid']['expose']['identifier'] = 'field_state_tid';
  $handler->display->display_options['filters']['field_state_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_state_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_state_tid']['vocabulary'] = 'state';
  $export['revision_history'] = $view;

  return $export;
}
