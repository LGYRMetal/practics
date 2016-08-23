<?php
/**
 * The template for displaying Comments.
 *
 * The area of the page that contains both current comments and the comment
 * form. The actual display of comments is handled by a callback to
 * shape_comment() which is located in inc/template-tags.php file.
 *
 * @package ShapeLGY
 * @since ShapeLGY 1.0
 */
?>

<?php
    /*
     * If the current post is protected by a password and the visitor has
     * not yet entered the password we will return early without loading
     * the comments.
     */
    if ( post_password_required() )
        return;
?>
    <div id="comments" class="comments-area">
        <?php // You can start editing here -- including this comment! ?>
        <?php if ( have_comments() ) : ?>
            <h2 class="comments-title">
                <?php printf(
                    _n(
                        'One thought on &ldquo;%2$s&rdquo;',
                        '%1$s thoughts on &ldquo;%2$s&rdquo;',
                        get_comments_number(),
                        'shape'
                    ),
                    number_format_i18n( get_comments_number() ),
                    '<span>' . get_the_title() . '</span>'
                ); ?>
            </h2>

            <?php
            // are there comments to navigate through? If so, show
            // navigation
            if ( get_comment_pages_count() > 1 &&
                 get_option( 'page_comments' ) ) :
            ?>
                <nav role="navigation" id="comment-nav-above"
                     class="site-navigation comment-navigation">
                    <h1 class="assistive-text">
                        <?php _e( 'Comment navigation', 'shape' ); ?>
                    </h1>
                    <div class="nav-previous">
                        <?php previous_comments_link( __(
                            '&larr; Older Comments',
                            'shape'
                        ) ); ?>
                    </div><!-- .nav-previous -->
                    <div class="nav-next">
                        <?php next_comments_link( __(
                            'Newer Comments &rarr;',
                            'shape'
                        ) ); ?>
                    </div><!-- .nav-next -->
                </nav>
<!-- #comment-nav-above .site-navigation .comment-navigation -->
            <?php endif; // check for comment navigation ?>
        <?php endif; ?>
    </div><!-- #comments .comments-area -->
