# Projeto ucLM3S1165

[English version](README.md)

**Projeto ucLM3S1165**

**Descrição:**
Projeto template para CLion, focado no desenvolvimento de firmwares para o microcontrolador LM3S1165, sem uso de placas de desenvolvimento da Texas Instruments.

**Repositório:**
[https://github.com/Inospher/ucLM3S1165.git](https://github.com/Inospher/ucLM3S1165.git)

**Propósito do Projeto:**

Este repositório oferece um template de projeto e exemplos baseados neste template, destinados ao desenvolvimento de firmwares para aplicações do microcontrolador LM3S1165. Este projeto não utiliza a placa de desenvolvimento da Texas Instruments (antiga Stellaris), focando no uso do microcontrolador em protoboards, PCBs desenvolvidas especificamente ou placas recicladas que utilizam o LM3S1165.

**Estrutura do Projeto:**

O projeto é organizado de maneira simples para facilitar o desenvolvimento:

- **Pasta 'samples'**: Contém projetos de exemplo, incluindo um template base que pode ser usado como ponto de partida para novos desenvolvimentos.
- **Pasta 'SDK'**: Inclui uma versão reduzida da SDK StellarisWare, com foco exclusivo nas bibliotecas e recursos necessários para o microcontrolador LM3S1165. Partes da SDK relacionadas a placas de desenvolvimento e bibliotecas gráficas foram removidas para manter o projeto enxuto e direcionado.

**Configuração do Ambiente de Desenvolvimento:**

**Ferramentas Necessárias:**
1. CLion 2024.2.1.
2. GNU Arm Embedded Toolchain: Pode ser baixada em [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads).
3. Ozone (SEGGER J-Link Debugger): Necessário para depuração e gravação do firmware no microcontrolador via interface J-TAG. Baixar em [Ozone Downloads](https://www.segger.com/downloads/jlink/#Ozone).
4. J-Link Interface: Uma interface J-Link é obrigatória para a comunicação entre o Ozone e o microcontrolador. Mais informações sobre os modelos disponíveis podem ser encontradas em [J-Link Models](https://www.segger.com/products/debug-probes/j-link/models/j-link-base/).

**Passos para Configuração:**

1. **Clone o Repositório:**
   - `git clone https://github.com/Inospher/ucLM3S1165.git`
2. **Abra o Projeto no CLion:**
   - Abra o CLion e selecione o diretório do projeto.
3. **Construa o Projeto:**
   - Execute a construção do projeto no CLion. Isso irá compilar o código e gerar o arquivo `.elf` no diretório `cmake-build-debug`.
4. **Gerar Projeto do Ozone:**
   - Ao compilar o projeto no CLion pela primeira vez, o script `CMakeLists.txt` automaticamente gerará um projeto para o Ozone no diretório `Ozone`.
5. **Depuração e Gravação no Microcontrolador:**
   - Abra o projeto gerado do Ozone.
   - Conecte a interface J-Link ao microcontrolador LM3S1165.
   - Use o Ozone para gravar o `.elf` no microcontrolador e iniciar a depuração.

**Estrutura de Diretórios pós abertura no CLion e primeiro build realizado:**
- **ucLM3S1165/**
  - **samples**: Projetos de exemplo e template base.
  - **SDK**: Conteúdo reduzido da SDK StellarisWare.
  - **cmake-build-debug**: Diretório de saída da construção do projeto.
  - **Ozone**: Projeto gerado para o Ozone.
