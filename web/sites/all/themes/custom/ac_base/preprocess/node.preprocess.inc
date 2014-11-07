<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_TEMPLATE().
 */
function ac_base_preprocess_node(&$variables) {
  $node = $variables['node'];

  $date = format_date($variables['created'], 'long');

  $variables['submitted'] = t('@date | <span class="author"><span class="label">Author:</span> !author</span>', array('@date' => $date, '!author' => $variables['name']));

  if (isset($node->comment_count)) {
    $comments = l(t('Comments (@comment_count)', array('@comment_count' => $variables['comment_count'])), 'node/' . $node->nid, array('fragment' => 'comments'));
    $variables['submitted'] .= " | $comments";
  }
}
