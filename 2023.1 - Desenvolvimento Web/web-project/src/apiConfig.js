import axios from 'axios'

const baseURL = 'http://localhost:1337'

export const api = axios.create({
  baseURL: `${baseURL}/api/`,
});


