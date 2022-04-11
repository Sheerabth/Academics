from factory import AzureFactory

if __name__ == "__main__":
    service_factory = AzureFactory()
    service = service_factory.get_service()
