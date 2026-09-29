CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pthread
BUILD_DIR := build
SRC_DIRS := content exercicies

.PHONY: help clean

help:
	@echo "Uso: make <nome_do_arquivo>   (sem o .cpp)"
	@echo "Exemplo: make classes"
	@echo "Procura o arquivo em content/ e exercicies/, compila e executa."
	@echo ""
	@echo "make clean   remove os binários gerados em $(BUILD_DIR)/"

clean:
	rm -rf $(BUILD_DIR)

# Regra "coringa": qualquer alvo que não seja 'help' ou 'clean' é tratado
# como o nome de um arquivo .cpp a procurar, compilar e rodar.
%:
	@name="$@"; \
	name="$${name%.cpp}"; \
	matches=$$(find $(SRC_DIRS) -type f -name "$$name.cpp" 2>/dev/null); \
	count=$$(printf '%s\n' "$$matches" | grep -c .); \
	if [ "$$count" -eq 0 ]; then \
		echo "Erro: nenhum arquivo '$$name.cpp' encontrado em $(SRC_DIRS)."; \
		exit 1; \
	fi; \
	if [ "$$count" -gt 1 ]; then \
		echo "Aviso: mais de um '$$name.cpp' encontrado, usando o primeiro:"; \
		printf '%s\n' "$$matches" | sed 's/^/  /'; \
	fi; \
	src=$$(printf '%s\n' "$$matches" | head -n1); \
	mkdir -p $(BUILD_DIR); \
	out="$(BUILD_DIR)/$$name"; \
	echo "==> Compilando $$src"; \
	$(CXX) $(CXXFLAGS) "$$src" -o "$$out" || exit 1; \
	echo "==> Executando $$out"; \
	echo "----------------------------------------"; \
	"$$out"
