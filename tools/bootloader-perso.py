# This tool is for development only, not to be used for releases

import argparse
import tempfile
import subprocess
import pathlib

def elf_to_bin(elf_path, out_path):
    subprocess.run(["arm-none-eabi-objcopy", "-O", "binary", "--gap-fill=255", elf_path, out_path], check=True)

def replace_elf_section(elf_path, section_name, section_content):
    subprocess.run(["arm-none-eabi-objcopy", "--update-section", f'.{section_name}={section_content}', elf_path, elf_path], check=True)

def main():
    parser = argparse.ArgumentParser(description='Create a database from a token and chain list')
    parser.add_argument('-p', '--public-key', help="the public key file")
    parser.add_argument('-e', '--elf', help="the bootloader ELF file")
    parser.add_argument('-o', '--output', help="the output binary file")
    args = parser.parse_args()
    
    with open(args.public_key) as f: 
        pub_key = bytearray.fromhex(f.read())

    with tempfile.NamedTemporaryFile('wb', delete=False) as f:
        f.write(pub_key)
        f.close()
        replace_elf_section(args.elf, "header", f.name)
        pathlib.Path.unlink(f.name)

    elf_to_bin(args.elf, args.output)

if __name__ == "__main__":
    main()