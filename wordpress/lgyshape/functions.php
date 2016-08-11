<?php
/**
 * ShapeLGY functions and definitions
 *
 * @package ShapeLGY
 * @since ShapeLGY 1.0
 */

if ( ! isset( $content_width ) )
    $content_width = 654; /* pixels */

if ( ! function_exists( 'shape_setup' ) ) :
/**
 * Sets up theme defaults and registers support for various
 * WordPress features.
 *
 * Note that this function is hooked into the after_setup_theme hook,
 * which runs before the init hook. The init hook is too late for some
 * features, such as indicating support post thumbnails.
 *
 * @since ShapeLGY 1.0
 */
function shape_setup() {

    /**
     * Custom template tags for this theme.
     */
    require( get_template_directory() . '/inc/template-tags.php' );

    /**
     * Custom functions that act independently of the theme templates
     */
    require( get_template_directory() . '/inc/tweaks.php' );

    /**
     * Make theme available for translation
     * Translations can be filed in the /languages/ directory
     * If you're building a theme based on Shape, use a find and replace
     * to change 'shape' to the name of your theme in all the template files
     */
    load_theme_textdomain( 
        'shape', get_template_directory() . 'languages'
    );

    /**
     * Add default posts and comments RSS feed links to head
     */
    add_theme_support( 'automatic-feed-links' );

    /**
     * Enable support for the Aside Post Format
     */
    add_theme_support( 'post-formats', array( 'aside' ) );

    /**
     * This theme uses wp_nav_menu() in one location.
     */
    register_nav_menus( array(
        'primary' => __( 'Primary Menu', 'shape' ),
    ) );
}
endif; // shape_setup
add_action( 'after_setup_theme', 'shape_setup' );
