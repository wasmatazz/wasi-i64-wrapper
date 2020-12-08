
const WASM_FILE = 'wrapper.wasm';

exports.getModule = (() => {
  if (typeof __dirname === 'string') {
    const path = require('path');
    const fs = require('fs');
    return () => new Promise((resolve, reject) => {
      fs.readFile(path.resolve(__dirname, WASM_FILE), (err, data) => {
        if (err) reject(err);
        else WebAssembly.compile(data).then(resolve, reject);
      });
    });
  }
  else {
    const url = (
      (require && typeof require.toURL === 'function') ? require.toURL(WASM_FILE)
      : URL && document && document.currentScript ? new URL(WASM_FILE, new URL(document.currentScript.src)).href
      : WASM_FILE
    );
    if (WebAssembly.compileStreaming) {
      return () => WebAssembly.compileStreaming(fetch(url));
    }
    else {
      return () => fetch(url).then(response => response.arrayBuffer()).then(buf => WebAssembly.compile(buf));
    }
  }
})();
