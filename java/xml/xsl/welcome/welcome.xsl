<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <xsl:apply-templates/>
        </html>
    </xsl:template>

    <xsl:template match="欢迎词">
        <head>
            <title><xsl:value-of select="标题"/></title>
        </head>
        <body>
            <xsl:value-of select="内容"/>
        </body>
    </xsl:template>
</xsl:stylesheet>
