<?php
/**
* Twenty Twelve setup.
*
* Sets up theme defaults and registers the various WordPress features that
* Twenty Twelve supports.
*
* @uses load_theme_textdomain() For translation/localization support.
* @uses add_editor_style() To add a Visual Editor stylesheet.
* @uses add_theme_support() To add support for post thumbnails, automatic feed links,
*  custom background, and post formats.
* @uses register_nav_menu() To add support for navigation menus.
* @uses set_post_thumbnail_size() To set a custom post thumbnail size.
*
* @since Twenty Twelve 1.0
*/
function mytheme_setup() {
    /*
     * Makes Twenty Twelve available for translation.
     *
     * Translations can be added to the /languages/ directory.
     * If you're building a theme based on Twenty Twelve, use a find and replace
     * to change 'twentytwelve' to the name of your theme in all the template files.
     */
    load_theme_textdomain( 'twentytwelve', get_template_directory() . '/languages' );

    // This theme styles the visual editor with editor-style.css to match the theme style.
    add_editor_style();

    // Adds RSS feed links to <head> for posts and comments.
    add_theme_support( 'automatic-feed-links' );

    // This theme supports a variety of post formats.
    add_theme_support( 'post-formats', array( 'aside', 'image', 'link', 'quote', 'status' ) );

    // This theme uses wp_nav_menu() in one location.
    register_nav_menu( 'primary', __( 'Primary Menu', 'twentytwelve' ) );

    /*
     * This theme supports custom background color and image,
     * and here we also set up the default background color.
     */
    add_theme_support( 'custom-background', array(
        'default-color' => 'e6e6e6',
    ) );

    // This theme uses a custom image size for featured images, displayed on "standard" posts.
    add_theme_support( 'post-thumbnails' );
    set_post_thumbnail_size( 624, 9999 ); // Unlimited height, soft crop

    // Indicate widget sidebars can use selective refresh in the Customizer.
    add_theme_support( 'customize-selective-refresh-widgets' );
}
add_action( 'after_setup_theme', 'mytheme_setup' );

/**
 * Register our sidebars and widgetized areas.
 *
 */
function mytheme_widgets_init() {

    register_sidebar(array(
        'name'          => __('Main sidebar', 'my-themes'),
        'id'            => 'sidebar-1',
        'before_widget' => '<div>',
        'after_widget'  => '</div>',
        'before_title'  => '<h2 class="rounded">',
        'after_title'   => '</h2>',
    ));
}
add_action('widgets_init', 'mytheme_widgets_init');
?>
