<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head></head>
            <xsl:apply-templates/>
        </html>
    </xsl:template>

    <xsl:template match="employees">
        <body>
            <table border="1">
                <xsl:apply-templates select="employee" mode="table"/>
            </table>
            <xsl:apply-templates select="employee" mode="list"/>
        </body>
    </xsl:template>

    <xsl:template match="employee" mode="table">
        <tr>
            <td><xsl:value-of select="name"/></td>
            <td><xsl:value-of select="age"/></td>
            <td><xsl:value-of select="monthly_pay"/></td>
        </tr>
    </xsl:template>

    <xsl:template match="employee" mode="list">
        <ul>
            <li><xsl:value-of select="name"/></li>
            <li><xsl:value-of select="age"/></li>
            <li><xsl:value-of select="monthly_pay"/></li>
        </ul>
    </xsl:template>
</xsl:stylesheet>
