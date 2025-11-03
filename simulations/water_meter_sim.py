import time, random

PULSES_PER_LITER = 450
LEAK_THRESHOLD = 2000
flow_pulses = total_usage = 0
leak_detected = valve_open = True
old_time = time.time()

print("Fluxo | Total | Vazamento | Válvula")
while True:
    flow_pulses = random.randint(0, 75)
    leak = random.randint(0, 4095)
    if leak > LEAK_THRESHOLD and not leak_detected:
        leak_detected = True; valve_open = False
        print("*** VAZAMENTO! Válvula FECHADA ***")
    time.sleep(1)
    flow_rate = (flow_pulses * 60) / PULSES_PER_LITER
    total_usage += flow_rate / 60
    print(f"{flow_rate:5.2f} | {total_usage:6.2f} | {'SIM' if leak_detected else 'NÃO'} | {'ABERTA' if valve_open else 'FECHADA'}")
