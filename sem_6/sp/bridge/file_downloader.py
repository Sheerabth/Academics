from abc import ABC, abstractmethod

from file_download_provider import FileDownloadProvider


class FileDownloader(ABC):
    @abstractmethod
    def download(self, path: str) -> dict:
        pass

    @abstractmethod
    def store(self, object: dict) -> bool:
        pass


class ConcreteFileDownloader(FileDownloader):
    def __init__(self, provider: FileDownloadProvider) -> None:
        super().__init__()
        self.__provider = provider

    def download(self, path: str) -> dict:
        return self.__provider.download_file(path)

    def store(self, object: dict) -> bool:
        return self.__provider.store_file(object)
