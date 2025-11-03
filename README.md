# Medidores de Água Inteligentes com Detecção de Vazamento e Fechamento Automático (Integração com TagoIO)

Este repositório contém um projeto DIY completo para um sistema de monitoramento de água inteligente usando ESP32, integrado à plataforma IoT TagoIO. O sistema:
- Monitora o consumo de água em tempo real.
- Detecta vazamentos via sensor de umidade.
- Fecha automaticamente a válvula de água em caso de vazamento.
- Envia dados para dashboards na TagoIO com alertas.

Inspirado na documentação da TagoIO (docs.tago.io) e projetos DIY de ESP32 (ex: esp32io.com, circuitdigest.com).

## Funcionalidades
- Leitura de fluxo de água (sensor YF-S201).
- Detecção de vazamento com fechamento automático (válvula solenoide + relé).
- Envio de dados via HTTP para TagoIO.
- Dashboard com gráficos, gauges e alertas.

## Hardware Recomendado
Baseado em buscas por medidores inteligentes com shutoff automático (2025):
- **Moen Flo Smart Water Monitor + Shutoff** (recomendado para inspiração comercial).
- Componentes DIY: ESP32, YF-S201 (fluxo), sensor capacitivo (vazamento), válvula 12V, relé.
