# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -O2

# Каталоги
BIN_DIRECT = bin
OBJ_DIRECT = $(BIN_DIRECT)/obj

# Исходные файлы и заголовкиб необходимые для сборки
SRC = testcmp.cpp mycomplex.cpp
HEADERS = mycomplex.h

# Объектные файлы
OBJ = $(OBJ_DIRECT)/testcmp.o $(OBJ_DIRECT)/mycomplex.o

# Итоговый исполняемый файл
PROG = $(BIN_DIRECT)/program.exe

# Сборка всех целей
all: $(PROG)

# Сборка исполняемого файла
$(PROG): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Сборка объектных файлов
$(OBJ_DIRECT)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJ) $(BIN_DIRECT)/program.exe
