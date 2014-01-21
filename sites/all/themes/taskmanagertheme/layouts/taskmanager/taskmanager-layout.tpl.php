<div<?php print $attributes; ?>>
  <header class="l-header" role="banner" id="header">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <?php if ($site_name): ?>
        <h1 class="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
            <span><?php print $site_name; ?></span>
          </a>
        </h1>
      <?php endif; ?>

      <?php if ($site_slogan): ?>
        <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
      <?php endif; ?>
    <?php endif; ?>
    <div class="l-menu" role="">
      <?php print render($page['menu']); ?>

      <?php global $user; ?>
      <?php if ($user->uid) : ?>
        <a class="login-link" href="/user/logout"><i class="ion ion-log-out"></i><span>Log out</span></a>
      <?php else : ?>
        <a class="login-link" href="/user"><i class="ion ion-log-in"></i><span>Login</span></a>
      <?php endif; ?>
    </div>
  </header>

  
  <div class="l-main" id="main" role="main">
    <div class="l-column-container">
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['column01']); ?>
      <?php print render($page['column02']); ?>
      <?php print render($page['column03']); ?>
      <?php print $feed_icons; ?>
    </div>
  </div>
  <div class="l-sidebar" id="sidebar">
    <?php print render($page['sidebar']); ?>
  </div>
  <div class="l-sidebar-toggle" id="sidebar-toggle">
    <i class="ion ion-chevron-up" id="ion-chevron-up"></i>
  </div>
</div>
