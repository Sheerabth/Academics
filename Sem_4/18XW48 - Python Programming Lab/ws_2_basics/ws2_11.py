def execute(variables,expression):
    try:
        return eval(expression,variables)
    except NameError:
        print('Value not defined')
        return 


if __name__ == '__main__':
    print('Enter the command - ')
    variables = {}
    try:
        while 1 :
            command = input('Please enter the input')
            if 'print' in command.lower():
                expression = command.split('print ')
                result = execute(variables,expression[1])
                print(result)
            elif 'let' in command.lower():
                equal_index = command.find('=')
                let_index = command.find('let')
                value = execute(variables,command[equal_index+1 :])
                variables[command[let_index+4:equal_index-1]] = value
            elif command == 'clear':
                variables.clear()
            elif command == 'exit':
                break
    except KeyboardInterrupt:
        print(' Keyboard Interrupt!')