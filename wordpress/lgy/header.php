<?php
/**
 * The template for displaying the header
 *
 * Displays all of the head element and everything up until the </header>.
 *
 * @package lgy
 */
?><!DOCTYPE html>
<html <?php language_attributes(); ?> class="no-js">
<head>
    <meta charset="<?php bloginfo('charset'); ?>">
    <meta name="viewport" content="initial-scale=1.0,user-scalable=no,maximum-scale=1,width=device-width">
    <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=1">
    <meta name="renderer" content="webkit">
    <link rel='stylesheet' id='rs-plugin-settings-css'  href='<?php bloginfo('template_url'); ?>/css/settings.css' type='text/css' media='all' />
    <style id='rs-plugin-settings-inline-css' type='text/css'>
    .tp-caption a{color:#ff7302;text-shadow:none;-webkit-transition:all 0.2s ease-out;-moz-transition:all 0.2s ease-out;-o-transition:all 0.2s ease-out;-ms-transition:all 0.2s ease-out}.tp-caption a:hover{color:#ffa902}.tp-caption a{color:#ff7302;text-shadow:none;-webkit-transition:all 0.2s ease-out;-moz-transition:all 0.2s ease-out;-o-transition:all 0.2s ease-out;-ms-transition:all 0.2s ease-out}.tp-caption a:hover{color:#ffa902}.tp-caption a.btn,.tp-caption a.btn:hover{color:#fff}
    </style>
    <link rel='stylesheet' id='stylesheet-css'  href='<?php bloginfo('template_url'); ?>/css/style.css' type='text/css' media='all' />
    <script type='text/javascript' src='<?php bloginfo('template_url'); ?>/js/jquery.min.js'></script>
    <script type='text/javascript' src='<?php bloginfo('template_url'); ?>/js/jquery.themepunch.tools.min.js'></script>
    <script type='text/javascript' src='<?php bloginfo('template_url'); ?>/js/jquery.themepunch.revolution.min.js'></script>
    <!--  lgy主题相关信息开始 -->
    <meta name="applicable-device" content="pc,mobile">
    <link rel="shortcut icon" href="<?php bloginfo('template_url'); ?>/favicon.ico">
    <meta name="keywords" content="旌准医疗">
    <meta name="description" content="旌准医疗官网">
    <!--  主题相关信息结束 -->
    <style>
                a,.page-title .title span,.sidebar .widget-title span,.header-1 .header-menu .navbar-nav>li.active>a, .header-1 .header-menu .navbar-nav>li.active>a:hover,.header-1 .header-menu .navbar-nav>li>a:hover,.header-1 .header-menu .navbar-nav>li>a:focus,.header-1 .header-menu .navbar-nav>li>a:active,.header-1 .header-menu .navbar-nav>li:hover>a,.sec-title span,.tel-title,.tel-num,.tell-icon,.header-2 .navbar-nav>li.active>a,.header-2 .search-icon:hover{color: #0088cc;}
        a:hover,.sidebar .widget ul a:hover, .sidebar .widget ol a:hover,.post-list .entry-title a:hover,.sec-title .more:hover,.p-item-wrap:hover .title a,.news-list a:hover,.bookmarks a:hover,.header-2 .navbar-nav>li a:hover{color: #0077cc;}
        .search-form input.submit,.header-1 .header-menu,.header-1 .header-menu .dropdown-menu>li>a:hover,.header-1 .header-menu .dropdown-menu>li>a:focus,.q-href .q-img:after,.pagination .current,.pagination a:hover,.sidebar .widget_nav_menu,.action .contact-title,.flex-control-paging li a.flex-active,.navbar-default .navbar-toggle:active .icon-bar, .navbar-default .navbar-toggle:hover .icon-bar, .navbar-default .navbar-toggle:focus .icon-bar,.header-1 .navbar-collapse,.dropdown-menu>.active>a, .dropdown-menu>.active>a:hover, .dropdown-menu>.active>a:focus,.form-submit .submit{background-color: #0088cc;}
        .search-form input.submit:hover,.sidebar .widget_nav_menu ul li.current-menu-item a, .sidebar .widget_nav_menu ul li.current-post-parent a,.sidebar .widget_nav_menu ul li a:hover,.sidebar .widget_nav_menu ul li.current-menu-item .sub-menu a:hover, .sidebar .widget_nav_menu ul li.current-post-parent .sub-menu a:hover,.action .a-box:hover,.header-1 .header-menu .search-index .search-form input.submit,.flex-control-paging li a:hover,.form-submit .submit:hover{background-color: #0077cc;}
        .header-2 .navbar-nav>li.active>a{border-top-color: #0088cc;}
        .header-2 .navbar-nav>li a:hover{border-top-color: #0077cc;}
        .sec-title span,.sidebar .widget-title span,.page-title .title span{border-bottom-color:#0088cc;}
        .p-item-wrap:hover{border-color: #0077cc;}
        .tell-icon,.comment-respond input:focus,.comment-form-comment textarea:focus{border-color: #0088cc;}
        .j-share{position: fixed!important;top: 50%!important;}
        .footer{color: #666;background: #f3f3f3;}
        .footer a{color: #666;}
        .footer a:hover{color: #333;}
        .footer .menu li, .footer .footer-menu li{border-right-color: #666;}
    </style>
    <script> (function() {if (!/*@cc_on!@*/0) return;var e = "abbr, article, aside, audio, canvas, datalist, details, dialog, eventsource, figure, footer, header, hgroup, mark, menu, meter, nav, output, progress, section, time, video".split(', ');var i= e.length; while (i--){ document.createElement(e[i]) } })()</script>
    <!--[if lte IE 8]><script src="http://demo.izt8.com/third/wp-content/themes/Third/js/respond.min.js"></script><![endif]-->
<?php wp_head(); ?>
</head>
<body class="home blog">
<header class="header header-1 navbar-default">
    <div class="container clearfix">
        <div class="pull-left logo-wrap">
            <a class="logo" href="<?php bloginfo('home'); ?>">
                <img src="<?php bloginfo('template_url'); ?>/images/logo.png" alt="旌准医疗">
            </a>
        </div>
        <div class="pull-right tell-wrap">
            <div class="tell-icon">
                <div class="fa fa-phone">
                </div>
            </div>
            <div class="tel">
                <h3 class="tel-title">客服电话</h3>
                <p class="tel-num">400-000-0000</p>
            </div>
        </div>
    </div><!-- /.container -->
    <div class="header-menu">
        <div class="container clearfix">
<?php include(TEMPLATEPATH . '/searchform.php'); ?>
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-menu">
                    <span class="sr-only"> </span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
            </div>
            <nav class="collapse navbar-collapse navbar-left navbar-menu">
                <ul id="menu-menu" class="nav navbar-nav">
                    <li class="menu-item active">
                        <a href="<?php bloginfo('home'); ?>">首页</a>
                    </li>
                    <li class="menu-item dropdown">
                        <a href="<?php bloginfo('home')?>/category/product" class="dropdown-toggle">产品介绍</a>
                        <ul role="menu" class=" dropdown-menu">
                            <li class="menu-item">
                                <a href="#">包装设计</a>
                            </li>
                            <li class="menu-item">
                                <a href="#">商业海报</a>
                            </li>
                            <li class="menu-item">
                                <a href="#">婚礼纸品</a>
                            </li>
                            <li class="menu-item">
                                <a href="#">食品广告</a>
                            </li>
                        </ul>
                    </li>
                    <li class="menu-item dropdown">
                        <a href="<?php bloginfo('home'); ?>/category/news" class="dropdown-toggle">新闻动态</a>
                        <ul role="menu" class=" dropdown-menu">
                            <li class="menu-item">
                                <a href="#">媒体报道</a>
                            </li>
                        </ul>
                    </li>
                    <li class="menu-item">
                        <a href="<?php bloginfo('home'); ?>/contact">联系我们</a>
                    </li>
                    <li class="menu-item">
                        <a href="<?php bloginfo('home'); ?>/about">关于我们</a>
                    </li>
                </ul>
            </nav><!-- /.navbar-collapse -->
        </div>
    </div>
</header>
