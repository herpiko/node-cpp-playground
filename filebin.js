const { spawnSync } = require('child_process');
const path = require('path');

const addonPath = path.join(__dirname, 'build', 'Release', 'filebin.node');

function writeToFile(text, filePath) {
      const result = spawnSync(addonPath, ['write', text, filePath]);
      if (result.error) {
                throw result.error;
            }
      if (result.stderr && result.stderr.toString() !== '') {
                throw new Error(result.stderr.toString());
            }
}

function readFromFile(filePath) {
      const result = spawnSync(addonPath, ['read', filePath]);
      if (result.error) {
                throw result.error;
            }
      if (result.stderr && result.stderr.toString() !== '') {
                throw new Error(result.stderr.toString());
            }
      return result.stdout.toString();
}

module.exports = {
      writeToFile,
      readFromFile
};

