# Medidores de Água Inteligentes com TagoIO

Sistema DIY com ESP32:  
- Monitora fluxo (YF-S201)  
- Detecta vazamento e fecha válvula automaticamente  
- Envia dados para TagoIO  

## Funcionalidades
- Fluxo em L/min  
- Consumo total  
- Alerta de vazamento  
- Dashboard na TagoIO  

## Hardware
- ESP32  
- YF-S201 (fluxo)  
- Sensor de vazamento  
- Válvula solenoide 12V + relé  

> Detalhes: [docs/hardware.md](docs/hardware.md)

## Código
[src/main.ino](src/main.ino)

## CI/CD
[![CI](https://github.com/SEU_USUARIO/smart-water-meter-tagoio/actions/workflows/ci.yml/badge.svg)](https://github.com/SEU_USUARIO/smart-water-meter-tagoio/actions)

## Simulação
`python simulations/water_meter_sim.py`

## Licença
MIT
