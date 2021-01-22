def return_absolute(real, img):
    if img == 0:
        if real < 0:
            real = -real
        return real
    else:
        return ((real**2)+(img**2))**0.5

if __name__ == '__main__':
    real = int(input("Please enter the real part: "))
    img = int(input("Please enter the imaganary part: "))
    print(return_absolute(real, img))