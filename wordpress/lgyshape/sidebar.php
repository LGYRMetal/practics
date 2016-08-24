<?php
/**
 * The Sidebar containing the main widget areas.
 *
 * @package ShapeLGY
 * @since ShapeLGY 1.0
 */
?>
<div id="secondary" class="widget-area" role="complementary">
    <?php do_action( 'before_sidebar' ); ?>
    <?php if ( ! dynamic_sidebar( 'sidbar-1' ) ) : ?>
        <aside id="search" class="widget widget_search">
            <?php get_search_form(); ?>
        </asid><!-- #search .widget .widget_search -->

        <aside id="archives" class="widget">
            <h1 class="widget-title">
                <?php _e( 'Archives', 'shape' ); ?>
            </h1>
            <ul>
                <?php wp_get_archives( array( 'type' => 'monthly' ) ); ?>
            </ul>
        </aside><!-- #archives .widget -->

        <aside id="meta" class="widget">
            <h1 class="widget-title"><?php _e( 'Meta', 'shape' ); ?></h1>
            <ul>
                <?php wp_register(); ?>
                <li><?php wp_loginout(); ?></li>
                <?php wp_meta(); ?>
            </ul>
        </aside><!-- #meta .widget -->
    <?php endif; ?>
</div><!-- #secondary .widget-area -->

<?php if ( is_active_sidebar( 'sidebar-2' ) ) : ?>
<div id="tertiary" class="widget-area" role="supplementary">
    <?php dynamic_sidebar( 'sidebar-2' ); ?>
</div><!-- #tertiary .widget-area -->
<?php endif; ?>
