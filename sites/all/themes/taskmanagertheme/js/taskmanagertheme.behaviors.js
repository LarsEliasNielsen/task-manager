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

  Drupal.theme.prototype.tableDragChangedWarning = function () {
    $tabledragWarning = $('<div></div>');
    // $tabledragWarning.attr('id', 'draggable-changed');
    $tabledragWarning.addClass('tabledrag-changed-warning messages warning');

    $tabledragWarning.append(Drupal.theme('tableDragChangedMarker') + '' + Drupal.t('Click \'Save\' to apply new order.'));
    $tabledragWarning.append($('#edit-actions'));
    $('#edit-actions').toggleClass('ninja');

    return $tabledragWarning;
  };

  Drupal.theme.prototype.tableDragChangedMarker = function () {
    return '<span class="ion-ios7-information-outline warning tabledrag-changed"></span>';
  };
  // TODO: remove tableDragChangedMarker after save

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
      // processed previously. By using .once('tmt-init') all processed elements will
      // get tagged with a 'tmt-init-processed' class, causing all future invocations
      // of this behavior to ignore them.

      // hidding Save button for tabledrag list
      $('#edit-actions').toggleClass('ninja');

        // PLACING TABLEDRAG HANDLE
      $('.tabledrag-handle', context).once('tmt-init', function () {
        // handle
        var $handle = $('.tabledrag-handle .handle');
        $handle.replaceWith('<i class="ion ion-ios7-more"></i>');
      });

      // SIDEBAR SCROLL
      $('#sidebar', context).once('tmt-init', function () {
        // accounting for admin-menu when setting variables
        if ($('body').hasClass('adminimal-menu')) {
          $viewportHeight = $(window).height()-29;
          $topHeight = $('#header').height() +29;
          $fixedTopHeight = '29px';
        } else {
          $viewportHeight = $(window).height();
          $topHeight = $('#header').height();
          $fixedTopHeight = '0';
        }

        $headerHeight = $('#header').height();
        $sidebarHeight = $viewportHeight - $headerHeight;
        $mainHeight = $('#main').height();

        // initial styling
        $('#sidebar').css({ 'position':'absolute', 'top':$topHeight, 'height':$sidebarHeight });
        $('#sidebar-toggle').css({ 'position':'absolute', 'top':$topHeight, 'height':$sidebarHeight });

        // use scroll function when #main is long enough
        if ($mainHeight >= $sidebarHeight) {
          $(window).scroll(function () {
            $windowScroll = $(window).scrollTop();
            if ($windowScroll <= 118) {
              $('#sidebar').css({ 'position':'absolute', 'top':$topHeight, 'height':($sidebarHeight+$windowScroll) });
              $('#sidebar-toggle').css({ 'position':'absolute', 'top':$topHeight, 'height':($sidebarHeight+$windowScroll) });
            } else {
              $('#sidebar').css({ 'position':'fixed', 'top':$fixedTopHeight, 'height':($viewportHeight) });
              $('#sidebar-toggle').css({ 'position':'fixed', 'top':$fixedTopHeight, 'height':($viewportHeight) });
            }
          });
        }
      });
    }
  }

  Drupal.behaviors.taskmanagerthemeHover = {
    attach: function (context, settings) {

      $('#draggableviews-table-columns-backlog', context).once('tmt-hover', function () {
        // task
        var $task = $('#draggableviews-table-columns-backlog tr.draggable');
        // initially hidden
        $task.find('.ion-ios7-more').hide();
        $task.find('.views-field-title a').css('margin-left', '10px');
        // hover
        $task.hover(
          function () {
            $(this).find('.ion-ios7-more').show();
            $(this).find('.views-field-title a').css('margin-left', '0');
          }, 
          function () {
            $(this).find('.ion-ios7-more').hide();
            $(this).find('.views-field-title a').css('margin-left', '10px');
          }
        );
      });
    }
  }

  Drupal.behaviors.taskmanagerthemeSidebar = {

    attach: function (context, settings) {
      $('#sidebar', context).once('tmt-sidebar', function () {
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
