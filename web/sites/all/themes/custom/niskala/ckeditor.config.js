/*
 WARNING: clear browser's cache after you modify this file.
 If you don't do this, you may notice that browser is ignoring all your changes.
 */
CKEDITOR.editorConfig = function(config) {
  config.indentClasses =
    ['rteindent1', 'rteindent2', 'rteindent3', 'rteindent4'];

  // [ Left, Center, Right, Justified ]
  config.justifyClasses = ['rteleft', 'rtecenter', 'rteright', 'rtejustify'];

  // The minimum editor width, in pixels, when resizing it with the resize handle.
  config.resize_minWidth = 450;

  // Protect PHP code tags (<?...?>) so CKEditor will not break them when
  // switching from Source to WYSIWYG.
  // Uncommenting this line doesn't mean the user will not be able to type PHP
  // code in the source. This kind of prevention must be done in the server
  // side
  // (as does Drupal), so just leave this line as is.
  config.protectedSource.push(/<\?[\s\S]*?\?>/g); // PHP Code
  config.protectedSource.push(/<code>[\s\S]*?<\/code>/gi); // Code tags
  config.extraPlugins = '';

  /*
   * Append here extra CSS rules that should be applied into the editing area.
   * Example:
   * config.extraCss = 'body {color:#FF0000;}';
   */
  config.extraCss = 'body { padding: 1em; }';

  /**
   * CKEditor's editing area body ID & class.
   * See http://drupal.ckeditor.com/tricks
   * This setting can be used if CKEditor does not work well with your theme by default.
   */
  config.bodyClass = '';
  config.bodyId = '';
}
