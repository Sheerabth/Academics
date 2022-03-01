from Builder import Builder

class TextReportBuilder(Builder):

    def __init__(self) -> None:
        self.report = ''

    def add_header(self):
        self.report += "Text Report:\n"
    
    def add_mean(self, value):
        self.report += "Mean {}\n".format(value)

    def add_min(self, value):
        self.report += "Min {}\n".format(value)

    def add_max(self, value):
        self.report += "Max {}\n".format(value)

    def add_footer(self):
        self.report += "End of Report"

    def build(self):
        return self.report
