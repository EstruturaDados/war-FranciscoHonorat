<<<<<<< HEAD
# 🎮 WAR - Jogo de Estratégia em C

Implementação do clássico jogo de tabuleiro WAR em linguagem C, desenvolvido como projeto acadêmico para a disciplina de Estrutura de Dados.

## 📸 Screenshots

```
╔════════════════════════════════════════════════════════════╗
║               🎮 GAME WAR - VERSAO 1.0 🎮                  ║
╚════════════════════════════════════════════════════════════╝
```

## ✨ Características

- ✅ **Sistema de Territórios** com alocação dinâmica de memória
- ✅ **Sistema de Ataque** com simulação de rolagem de dados (1-6)
- ✅ **Missões Estratégicas** para vitória
- ✅ **Código Modular** e bem documentado
- ✅ **Interface Terminal** interativa e intuitiva
- ✅ **Validações Robustas** de entrada do usuário
- ✅ **Gerenciamento de Memória** adequado (malloc/free)

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C (C11)
- **Compilador:** GCC (MinGW-w64)
- **Conceitos:**
  - Alocação dinâmica de memória (`malloc`, `calloc`, `free`)
  - Estruturas de dados (`struct`)
  - Ponteiros e passagem por referência
  - Modularização (arquivos `.h` e `.c` separados)
  - Enumerações (`enum`)
  - Manipulação de strings

## 📂 Estrutura do Projeto

```
war-FranciscoHonorat/
│
├── main.c              # Arquivo principal do jogo
├── territorio.h/c      # Sistema de gerenciamento de territórios
├── ataque.h/c         # Sistema de combate e ataques
├── missao.h/c         # Sistema de missões estratégicas
├── utilidades.h/c     # Funções auxiliares
├── README.md          # Documentação
└── .vscode/
    └── tasks.json     # Configurações de compilação
```

## 🚀 Como Compilar

### Windows (MinGW)

```bash
gcc main.c territorio.c ataque.c missao.c utilidades.c -o war.exe
```

### Linux / macOS

```bash
gcc main.c territorio.c ataque.c missao.c utilidades.c -o war
```

### Compilação com flags de debug

```bash
gcc main.c territorio.c ataque.c missao.c utilidades.c -o war.exe -Wall -Wextra -g
```

## 🎯 Como Executar

### Windows

```bash
.\war.exe
```

### Linux / macOS

```bash
./war
```

## 📖 Como Jogar

1. **Escolha a cor do seu exército**
2. **Cadastre os territórios** (nome, cor do exército, tropas)
3. **Receba sua missão secreta** (aparece no início do jogo)
4. **Ataque territórios inimigos:**
   - Escolha território atacante (deve ser seu)
   - Escolha território defensor (deve ser inimigo)
   - Dados serão rolados automaticamente
5. **Cumpra sua missão** para vencer!

## 🎲 Regras do Jogo

### Sistema de Ataque

- Atacante e defensor rolam 1 dado (1-6)
- **Se atacante vencer:** Defensor perde 1 tropa
- **Se defensor vencer:** Atacante perde 1 tropa
- **Conquista:** Quando defensor chega a 0 tropas
  - Território muda de dono
  - Metade das tropas do atacante são transferidas

### Tipos de Missão

1. **Destruir Exército:** Elimine completamente uma cor específica
2. **Conquistar Territórios:** Conquiste N territórios
3. **Dominar Continente:** Controle todos os territórios de um continente
4. **Conquista Total:** Domine quantidade específica de territórios

## 🧪 Funcionalidades Implementadas

### Módulo `territorio.c`

- Alocação dinâmica de territórios
- Cadastro interativo
- Validação de dados
- Exibição formatada

### Módulo `ataque.c`

- Simulação de dados
- Validação de ataques
- Transferência de propriedade
- Atualização de tropas

### Módulo `missao.c`

- Atribuição aleatória de missões
- Verificação automática de cumprimento
- Exibição de progresso
- 4 tipos diferentes de objetivos

### Módulo `utilidades.c`

- Limpeza de buffer
- Pausa de execução
- Limpeza de tela (multiplataforma)

## 💻 Requisitos de Sistema

- **Windows:** Windows 7 ou superior
- **Linux:** Qualquer distribuição moderna
- **macOS:** 10.9 ou superior
- **Compilador:** GCC 7.0+ ou Clang
- **Memória:** Mínimo 4MB RAM
- **Terminal:** Suporte a caracteres UTF-8 (opcional)

## 🐛 Problemas Conhecidos

- Emojis podem não aparecer corretamente em alguns terminais Windows antigos
  - **Solução:** Use Windows Terminal ou adicione `chcp 65001` antes de executar

## 📚 Conceitos de Programação Demonstrados

- ✅ Alocação dinâmica de memória
- ✅ Uso de ponteiros e referências
- ✅ Modularização de código
- ✅ Estruturas de dados complexas
- ✅ Enumerações para tipos
- ✅ Passagem por valor vs referência
- ✅ Gerenciamento de memória (malloc/free)
- ✅ Validação de entrada do usuário
- ✅ Manipulação de strings
- ✅ Números aleatórios (rand/srand)

## 👨‍💻 Autor

**Francisco Honorat**

- GitHub: [@EstruturaDados](https://github.com/EstruturaDados)
- Projeto: [war-FranciscoHonorat](https://github.com/EstruturaDados/war-FranciscoHonorat)

## 📝 Licença

Este projeto é de código aberto para fins educacionais.

## 🙏 Agradecimentos

Desenvolvido como projeto acadêmico para a disciplina de Estrutura de Dados.

---

⭐ **Se gostou do projeto, deixe uma estrela no GitHub!** ⭐
=======
# 🗺️ Desafio WAR Estruturado – Conquista de Territórios

Bem-vindo ao **Desafio WAR Estruturado!** Inspirado no famoso jogo de estratégia, este desafio convida você a programar diferentes versões do jogo WAR, evoluindo seus conhecimentos em **C** à medida que avança pelos níveis **Novato**, **Aventureiro** e **Mestre**.

A empresa **MateCheck** contratou você para criar uma versão estruturada do WAR. Cada nível propõe novas funcionalidades, conceitos e desafios de programação. **Você escolhe por onde começar!**

---

## 🧩 Nível Novato: Cadastro Inicial dos Territórios

### 🎯 Objetivo

- Criar uma `struct` chamada `Territorio`.
- Usar um **vetor estático de 5 elementos** para armazenar os territórios.
- Cadastrar os dados de cada território: **Nome**, **Cor do Exército**, e **Número de Tropas**.
- Exibir o estado atual do mapa.

### ⚙️ Funcionalidades

- Leitura de dados pelo terminal (`fgets` e `scanf`)
- Impressão organizada dos dados de todos os territórios

### 💡 Conceitos abordados

- `struct`
- Vetor estático
- Entrada/saída com `scanf`, `fgets`, e `printf`

### 📥 Entrada

O usuário digita o nome do território, a cor do exército dominante e o número de tropas para **cada um dos 5 territórios**.

### 📤 Saída



## 🧗‍♂️ Nível Aventureiro: Batalhas Estratégicas

### 🎯 Objetivo

- Substituir o vetor estático por **alocação dinâmica com `calloc`**
- Criar uma função para **simular ataques entre dois territórios**
- Utilizar números aleatórios para representar dados de batalha

### 🆕 Novidades em relação ao Nível Novato

- Alocação dinâmica de memória com `calloc`
- Uso de **ponteiros**
- Laço interativo para o jogador escolher **territórios para atacar e defender**
- Simulação de dados de ataque e defesa com `rand()`

### ⚙️ Funcionalidades

- Cadastro dos territórios (como no Nível Novato)
- Fase de ataque com:
  - Escolha de atacante e defensor
  - Dados de ataque/defesa
  - Lógica:
    - Se atacante vence → defensor perde 1 tropa
    - Se defensor perde todas → território é conquistado
    - Empates favorecem o atacante

### 💡 Conceitos abordados

- Ponteiros
- `calloc` / `free`
- Aleatoriedade com `rand()` / `srand()`
- Funções para modularização

### 📥 Entrada

- Território **atacante** (1 a 5)
- Território **defensor** (1 a 5)

### 📤 Saída

Exibição do resultado da batalha, dados sorteados e mudanças no mapa.



## 🧠 Nível Mestre: Missões e Modularização Total

### 🎯 Objetivo

- Dividir o código em funções bem definidas
- Implementar um **sistema de missões**
- Verificar cumprimento da missão
- Aplicar **boas práticas** (uso de `const`, modularização, etc.)

### 🆕 Diferenças em relação ao Nível Aventureiro

- Modularização total em funções
- Missões aleatórias atribuídas:
  1. Destruir o exército **Verde**
  2. Conquistar **3 territórios**
- Menu interativo com opções

### ⚙️ Funcionalidades

- Inicialização automática dos territórios
- Menu principal com 3 opções:
  1. Atacar
  2. Verificar Missão
  3. Sair
- Verificação de vitória da missão

### 💡 Conceitos abordados

- Modularização
- `const` correctness
- Estruturação em múltiplas funções
- Passagem por referência

### 📥 Entrada

- Ações do jogador via menu:
  - `1` - Atacar
  - `2` - Verificar Missão
  - `0` - Sair
- Escolha de territórios para ataque

### 📤 Saída

- Mapa atualizado
- Resultados das batalhas
- Verificação da missão
- Mensagem de vitória



## 🏁 Conclusão

Com este **Desafio WAR Estruturado**, você praticará fundamentos essenciais da linguagem **C** de forma **divertida e progressiva**.

Cada nível foca em um conjunto de habilidades:

- 🟢 **Novato**: `struct`, vetor, entrada/saída
- 🔵 **Aventureiro**: ponteiros, memória dinâmica, lógica de jogo
- 🟣 **Mestre**: modularização, design limpo, sistema de missões



🚀 **Boa sorte! Avance nos níveis e torne-se um mestre da programação estratégica!**

> Equipe de Ensino – MateCheck
>>>>>>> 9af5ac1be7c3def87f4c10634fc5181f2c8ef1af
