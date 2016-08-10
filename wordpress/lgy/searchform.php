<?php
/**
 * The template for displaying the searchform 
 */
?>
            <div class="pull-right search-index">
                <a class="search-icon" href="javascript:;"><i class="fa fa-search"></i></a>
                <form class="search-form" action="<?php bloginfo('home'); ?>" method="get" role="search">
                <input type="text" class="keyword" name="s" placeholder="输入关键词搜索..." value="">
                <input type="submit" class="submit" value="&#xf002;">
                </form>
            </div><!-- /.search-index -->
