from abc import ABC, abstractmethod


class FileDownloadProvider(ABC):
    @abstractmethod
    def download_file(self, path: str) -> dict:
        pass

    @abstractmethod
    def store_file(self, object: dict) -> bool:
        pass


class LinuxFileDownloadProvider(FileDownloadProvider):
    def download_file(self, path: str) -> dict:
        return {"content": "some linux content"}

    def store_file(self, object: dict) -> bool:
        print("File downloaded successfully in linux")
        return True


class WindowsFileDownloadProvider(FileDownloadProvider):
    def download_file(self, path: str) -> dict:
        return {"content": "some windows content"}

    def store_file(self, object: dict) -> bool:
        print("File downloaded successfully in windows")
        return True
