from Builder import Builder


class HTMLReportBuilder(Builder):
    def __init__(self):
        self.report = ""

    def add_header(self):
        self.report += "<html>\n"

    def add_mean(self, value):
        self.report += "\t<p>Mean {}</p>\n".format(value)

    def add_min(self, value):
        self.report += "\t<p>Min {}</p>\n".format(value)

    def add_max(self, value):
        self.report += "\t<p>Max {}</p>\n".format(value)

    def add_footer(self):
        self.report += "</html>\n"

    def build(self):
        return self.report
