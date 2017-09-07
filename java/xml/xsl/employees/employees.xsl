<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <xsl:apply-templates/>
    </xsl:template>

    <xsl:template match="employees">
        <xsl:apply-templates/>
    </xsl:template>

    <xsl:template match="employee">
        <xsl:apply-templates select="name"/>
    </xsl:template>
</xsl:stylesheet>
