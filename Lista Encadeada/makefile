# Variáveis do compilador e flags
CC = g++
CFLAGS = -Wall -std=c++11
TARGET = main

# Lista de fontes e objetos
SRCS = main.cpp lista.cpp no.cpp
OBJS = $(SRCS:.cpp=.o)

# Alvo padrão: compila o executável
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Alvo para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpa os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)
