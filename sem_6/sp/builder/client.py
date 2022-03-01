from TextReportBuilder import TextReportBuilder
from HTMLReportBuilder import HTMLReportBuilder
from ReportGenerator import ReportGenerator

if __name__ == "__main__":
    data = [4, 5, 8, 9, 2]

    generator = ReportGenerator(data)

    print(generator.create(TextReportBuilder()))
    print(generator.create(HTMLReportBuilder()))
