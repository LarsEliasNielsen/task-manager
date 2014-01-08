(function ($) {

  /**
   * The recommended way for producing HTML markup through JavaScript is to write
   * theming functions. These are similiar to the theming functions that you might
   * know from 'phptemplate' (the default PHP templating engine used by most
   * Drupal themes including Omega). JavaScript theme functions accept arguments
   * and can be overriden by sub-themes.
   *
   * In most cases, there is no good reason to NOT wrap your markup producing
   * JavaScript in a theme function.
   */
  Drupal.theme.prototype.taskmanagerthemeExampleButton = function (path, title) {
    // Create an anchor element with jQuery.
    return $('<a href="' + path + '" title="' + title + '">' + title + '</a>');
  };

  /**
   * Behaviors are Drupal's way of applying JavaScript to a page. The advantage
   * of behaviors over simIn short, the advantage of Behaviors over a simple
   * document.ready() lies in how it interacts with content loaded through Ajax.
   * Opposed to the 'document.ready()' event which is only fired once when the
   * page is initially loaded, behaviors get re-executed whenever something is
   * added to the page through Ajax.
   *
   * You can attach as many behaviors as you wish. In fact, instead of overloading
   * a single behavior with multiple, completely unrelated tasks you should create
   * a separate behavior for every separate task.
   *
   * In most cases, there is no good reason to NOT wrap your JavaScript code in a
   * behavior.
   *
   * @param context
   *   The context for which the behavior is being executed. This is either the
   *   full page or a piece of HTML that was just added through Ajax.
   * @param settings
   *   An array of settings (added through drupal_add_js()). Instead of accessing
   *   Drupal.settings directly you should use this because of potential
   *   modifications made by the Ajax callback that also produced 'context'.
   */

  Drupal.behaviors.taskmanagerthemeInit = {
    attach: function (context, settings) {
      // By using the 'context' variable we make sure that our code only runs on
      // the relevant HTML. Furthermore, by using jQuery.once() we make sure that
      // we don't run the same piece of code for an HTML snippet that we already
      // processed previously. By using .once('sidebar') all processed elements will
      // get tagged with a 'sidebar-processed' class, causing all future invocations
      // of this behavior to ignore them.

      $('.tabledrag-handle', context).once('tm-init', function () {
        // handle
        var $handle = $('.tabledrag-handle .handle');
        $handle.replaceWith('<i class="ion ion-ios7-more"></i>');
      });
    }
  }

  Drupal.behaviors.taskmanagerthemeHover = {
    attach: function (context, settings) {

      $('#draggableviews-table-columns-backlog', context).once('tm-hover', function () {
        // task
        var $task = $('#draggableviews-table-columns-backlog tr.draggable');
        // initially hidden
        $task.find('.ion-ios7-more').hide();
        $task.find('a').css('margin-left', '10px');
        // hover
        $task.hover(
          function () {
            $(this).find('.ion-ios7-more').show();
            $(this).find('a').css('margin-left', '0');
          }, 
          function () {
            $(this).find('.ion-ios7-more').hide();
            $(this).find('a').css('margin-left', '10px');
          }
        );
      });
    }
  }

  Drupal.behaviors.taskmanagerthemeSidebar = {

    attach: function (context, settings) {
      $('#sidebar', context).once('tm-sidebar', function () {
        // CLICK
        $('#sidebar-toggle').click(function() {
          // sidebar
          var $sidebar = $('#sidebar');
          $sidebar.animate({
            right: parseInt($sidebar.css('right'),10) == 0 ?
              -$sidebar.outerWidth() :
              0
          }, 100);
          // sidebartoggle
          var $sidebartoggle = $('#sidebar-toggle');
          $sidebartoggle.animate({
            right: parseInt($sidebartoggle.css('right'),10) == 0 ?
              230 :
              0
          }, 100);
          // main
          var $main = $('#main');
          $main.animate({
            paddingRight: parseInt($main.css('padding-right'),10) == 0 ?
              250 :
              0
          }, 100);
          // rotate
          var $rotate = $('#ion-chevron-up');
          $rotate.toggleClass('sidebar-collapsed');
        });
      });
    }
  };

})(jQuery);
