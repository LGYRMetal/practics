<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <xsl:apply-templates select="employees/employee" mode="link"/>
        <xsl:apply-templates select="employees/employee" mode="list"/>
    </xsl:template>

    <xsl:template match="employee" mode="link">
        <br><a href="#{position()}"><xsl:value-of select="@sn"/></a></br>
    </xsl:template>

    <xsl:template match="employee" mode="list">
        <ul id="#{position()}">
            <li><xsl:value-of select="name"/></li>
            <li><xsl:value-of select="age"/></li>
            <li><xsl:value-of select="monthly_pay"/></li>
        </ul>
    </xsl:template>
</xsl:stylesheet>
