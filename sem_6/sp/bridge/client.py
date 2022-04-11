from file_download_provider import (
    LinuxFileDownloadProvider,
    WindowsFileDownloadProvider,
)
from file_downloader import ConcreteFileDownloader

if __name__ == "__main__":
    os = "linux"
    downloader = None

    if os == "windows":
        downloader = ConcreteFileDownloader(WindowsFileDownloadProvider())

    elif os == "linux":
        downloader = ConcreteFileDownloader(LinuxFileDownloadProvider())

    else:
        print("OS not supported")

    file_content = downloader.download("some path")
    print(file_content)
    downloader.store(file_content)
