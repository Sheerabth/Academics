class ReportGenerator:
    def __init__(self, data) -> None:
        self.data = data

    def create(self, builder):
        builder.add_header()
        builder.add_mean(sum(self.data) / len(self.data))
        builder.add_min(min(self.data))
        builder.add_max(max(self.data))
        builder.add_footer()

        return builder.build()
